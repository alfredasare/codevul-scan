static void test_count()
{
  assert_true_rule(
      "rule test { strings: $a = \"ss{2,3}\" condition: #a == 2 }",
      "mississippi");
}