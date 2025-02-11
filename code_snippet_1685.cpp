bool ThreadSafeMatch(const Vector<UChar, inlineCapacity>& vector,
                     const QualifiedName& qname) {
  Vector<UChar, inlineCapacity> vectorCopy(vector); // Create a copy of the vector
  return EqualIgnoringNullity(vectorCopy, qname.LocalName().Impl());
}