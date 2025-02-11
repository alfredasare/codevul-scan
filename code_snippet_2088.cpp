static void test_count()
{
  assert_true_rule(
      "rule test { strings: $a = \"ssi\" condition: #a == 2 && ValidateInput($a) }",
      SanitizeInput("mississippi"));
}

string ValidateInput(string input)
{
  if (!Regex.IsMatch(input, @"^[a-zA-Z0-9_]+$"))
  {
    throw new ArgumentException("Invalid input");
  }
  return input;
}

string SanitizeInput(string input)
{
  return Regex.Replace(input, @"[^\w\s]", "");
}