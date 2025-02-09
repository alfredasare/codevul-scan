int ecc_projective_dbl_point(ecc_point *P, ecc_point *R, mp_int* a,
                                       mp_int* modulus, mp_digit mp)
{
#ifndef WOLFSSL_SP_MATH
   mp_int t1, t2;
#ifdef ALT_ECC_SIZE
   mp_int rx, ry, rz;
#endif
   mp_int *x, *y, *z;
   int    err;

   if (P == NULL || R == NULL || modulus == NULL)
       return ECC_BAD_ARG_E;

   if ((err = mp_init_multi(&t1, &t2, NULL, NULL, NULL, NULL)) != MP_OKAY) {
      return err;
   }

/* If use ALT_ECC_SIZE we need to use local stack variable since
   ecc_point x,y,z is reduced size */
#ifdef ALT_ECC_SIZE
   /* Use local stack variable */
   x = &rx;
   y = &ry;
   z = &rz;

   if ((err = mp_init_multi(x, y, z, NULL, NULL, NULL)) != MP_OKAY) {
       mp_clear(&t1);
       mp_clear(&t2);
       return err;
   }
#else
   /* Use destination directly */
   x = R->x;
   y = R->y;
   z = R->z;
#endif

   if (err == MP_OKAY)
       err = mp_copy(P->x, x);
   if (err == MP_OKAY)
       err = mp_copy(P->y, y);
   if (err == MP_OKAY)
       err = mp_copy(P->z, z);

   /* T1 = Z * Z */
   if (err == MP_OKAY)
       err = mp_sqr(z, &t1);
   if (err == MP_OKAY)
       err = mp_montgomery_reduce(&t1, modulus, mp);

   /* Z = Y * Z */
   if (err == MP_OKAY)
       err = mp_mul(z, y, z);
   if (err == MP_OKAY)
       err = mp_montgomery_reduce(z, modulus, mp);

   /* Z = 2Z */
   if (err == MP_OKAY)
       err = mp_add(z, z, z);
   if (err == MP_OKAY) {
       if (mp_cmp(z, modulus) != MP_LT)
           err = mp_sub(z, modulus, z);
   }

   /* Determine if curve "a" should be used in calc */
#ifdef WOLFSSL_CUSTOM_CURVES
   if (err == MP_OKAY) {
      /* Use a and prime to determine if a == 3 */
      err = mp_submod(modulus, a, modulus, &t2);
   }
   if (err == MP_OKAY && mp_cmp_d(&t2, 3) != MP_EQ) {
      /* use "a" in calc */

      /* T2 = T1 * T1 */
      if (err == MP_OKAY)
          err = mp_sqr(&t1, &t2);
      if (err == MP_OKAY)
          err = mp_montgomery_reduce(&t2, modulus, mp);
      /* T1 = T2 * a */
      if (err == MP_OKAY)
          err = mp_mulmod(&t2, a, modulus, &t1);
      /* T2 = X * X */
      if (err == MP_OKAY)
          err = mp_sqr(x, &t2);
      if (err == MP_OKAY)
          err = mp_montgomery_reduce(&t2, modulus, mp);
      /* T1 = T2 + T1 */
      if (err == MP_OKAY)
          err = mp_add(&t1, &t2, &t1);
      if (err == MP_OKAY) {
         if (mp_cmp(&t1, modulus) != MP_LT)
            err = mp_sub(&t1, modulus, &t1);
      }
      /* T1 = T2 + T1 */
      if (err == MP_OKAY)
          err = mp_add(&t1, &t2, &t1);
      if (err == MP_OKAY) {
          if (mp_cmp(&t1, modulus) != MP_LT)
              err = mp_sub(&t1, modulus, &t1);
      }
      /* T1 = T2 + T1 */
      if (err == MP_OKAY)
          err = mp_add(&t1, &t2, &t1);
      if (err == MP_OKAY) {
         if (mp_cmp(&t1, modulus) != MP_LT)
            err = mp_sub(&t1, modulus, &t1);
      }
   }
   else
#endif /* WOLFSSL_CUSTOM_CURVES */
   {
      /* assumes "a" == 3 */
      (void)a;

      /* T2 = X - T1 */
      if (err == MP_OKAY)
          err = mp_sub(x, &t1, &t2);
      if (err == MP_OKAY) {
          if (mp_isneg(&t2))
              err = mp_add(&t2, modulus, &t2);
      }
      /* T1 = X + T1 */
      if (err == MP_OKAY)
          err = mp_add(&t1, x, &t1);
      if (err == MP_OKAY) {
          if (mp_cmp(&t1, modulus) != MP_LT)
              err = mp_sub(&t1, modulus, &t1);
      }
      /* T2 = T1 * T2 */
      if (err == MP_OKAY)
          err = mp_mul(&t1, &t2, &t2);
      if (err == MP_OKAY)
          err = mp_montgomery_reduce(&t2, modulus, mp);

      /* T1 = 2T2 */
      if (err == MP_OKAY)
          err = mp_add(&t2, &t2, &t1);
      if (err == MP_OKAY) {
          if (mp_cmp(&t1, modulus) != MP_LT)
              err = mp_sub(&t1, modulus, &t1);
      }
      /* T1 = T1 + T2 */
      if (err == MP_OKAY)
          err = mp_add(&t1, &t2, &t1);
      if (err == MP_OKAY) {
          if (mp_cmp(&t1, modulus) != MP_LT)
              err = mp_sub(&t1, modulus, &t1);
      }
   }

   /* Y = 2Y */
   if (err == MP_OKAY)
       err = mp_add(y, y, y);
   if (err == MP_OKAY) {
       if (mp_cmp(y, modulus) != MP_LT)
           err = mp_sub(y, modulus, y);
   }
   /* Y = Y * Y */
   if (err == MP_OKAY)
       err = mp_sqr(y, y);
   if (err == MP_OKAY)
       err = mp_montgomery_reduce(y, modulus, mp);

   /* T2 = Y * Y */
   if (err == MP_OKAY)
       err = mp_sqr(y, &t2);
   if (err == MP_OKAY)
       err = mp_montgomery_reduce(&t2, modulus, mp);

   /* T2 = T2/2 */
   if (err == MP_OKAY) {
       if (mp_isodd(&t2) == MP_YES)
           err = mp_add(&t2, modulus, &t2);
   }
   if (err == MP_OKAY)
       err = mp_div_2(&t2, &t2);

   /* Y = Y * X */
   if (err == MP_OKAY)
       err = mp_mul(y, x, y);
   if (err == MP_OKAY)
       err = mp_montgomery_reduce(y, modulus, mp);

   /* X = T1 * T1 */
   if (err == MP_OKAY)
       err = mp_sqr(&t1, x);
   if (err == MP_OKAY)
       err = mp_montgomery_reduce(x, modulus, mp);

   /* X = X - Y */
   if (err == MP_OKAY)
       err = mp_sub(x, y, x);
   if (err == MP_OKAY) {
       if (mp_isneg(x))
           err = mp_add(x, modulus, x);
   }
   /* X = X - Y */
   if (err == MP_OKAY)
       err = mp_sub(x, y, x);
   if (err == MP_OKAY) {
       if (mp_isneg(x))
           err = mp_add(x, modulus, x);
   }

   /* Y = Y - X */
   if (err == MP_OKAY)
       err = mp_sub(y, x, y);
   if (err == MP_OKAY) {
       if (mp_isneg(y))
           err = mp_add(y, modulus, y);
   }
   /* Y = Y * T1 */
   if (err == MP_OKAY)
       err = mp_mul(y, &t1, y);
   if (err == MP_OKAY)
       err = mp_montgomery_reduce(y, modulus, mp);

   /* Y = Y - T2 */
   if (err == MP_OKAY)
       err = mp_sub(y, &t2, y);
   if (err == MP_OKAY) {
       if (mp_isneg(y))
           err = mp_add(y, modulus, y);
   }

#ifdef ALT_ECC_SIZE
   if (err == MP_OKAY)
       err = mp_copy(x, R->x);
   if (err == MP_OKAY)
       err = mp_copy(y, R->y);
   if (err == MP_OKAY)
       err = mp_copy(z, R->z);
#endif

   /* clean up */
   mp_clear(&t1);
   mp_clear(&t2);

   return err;
#else
    if (P == NULL || R == NULL || modulus == NULL)
        return ECC_BAD_ARG_E;

    (void)a;
    (void)mp;

    return sp_ecc_proj_dbl_point_256(P->x, P->y, P->z, R->x, R->y, R->z);
#endif
}
