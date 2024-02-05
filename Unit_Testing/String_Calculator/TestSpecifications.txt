GIVEN: "";
WHEN: Add Called
THEN: Result = 0

GIVEN: "1"
WHEN: Add Called
THEN: Result = 1

GIVEN: "1,2";
WHEN: Add Called
THEN: Result = 3

GIVEN: “1\n2,3”
WHEN: Add Called
THEN: Result = 6


GIVEN: "1,\n"
WHEN: Add Called
THEN: Result = InvalidParameterException()

GIVEN: "//;\n1;2"
WHEN: Add Called
THEN: Result = 3

GIVEN: "-1;2"
WHEN: Add Called
THEN: Result = InvalidParameterException("Negatives Not Allowed");

GIVEN: "2,1001"
WHEN: Add Called
THEN: Result = 2

GIVEN: "//[***]\n1***2***3"
WHEN: Add Called
THEN: Result = 6

GIVEN: "//[*][%]\n1*2%3"
WHEN: Add Called
THEN: Result = 6

GIVEN: "1*****3"
WHEN: Add Called
THEN: Result = 4
