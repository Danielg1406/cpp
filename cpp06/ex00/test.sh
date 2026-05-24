#!/bin/bash

EXEC="./convert"

if [ ! -f "$EXEC" ]; then
	echo "Error: executable './convert' not found."
	echo "Run 'make' first."
	exit 1
fi

run_test()
{
	echo "Input given to ./convert: [$1]"
	$EXEC "$1"
	echo
}

echo "========================================"
echo " CHAR LITERALS"
echo "========================================"
run_test "a"
run_test "c"
run_test "Z"

echo "========================================"
echo " INT LITERALS"
echo "========================================"
run_test "0"
run_test "42"
run_test "-42"
run_test "127"
run_test "128"

echo "========================================"
echo " FLOAT LITERALS"
echo "========================================"
run_test "0.0f"
run_test "42.0f"
run_test "-42.42f"
run_test "127.0f"
run_test "128.0f"

echo "========================================"
echo " DOUBLE LITERALS"
echo "========================================"
run_test "0.0"
run_test "42.0"
run_test "-42.42"
run_test "127.0"
run_test "128.0"

echo "========================================"
echo " FLOAT PSEUDO-LITERALS"
echo "========================================"
run_test "nanf"
run_test "+inff"
run_test "-inff"

echo "========================================"
echo " DOUBLE PSEUDO-LITERALS"
echo "========================================"
run_test "nan"
run_test "+inf"
run_test "-inf"

echo "========================================"
echo " NON-DISPLAYABLE CHAR CASES"
echo "========================================"
run_test "0"
run_test "10"

echo "========================================"
echo " IMPOSSIBLE / OVERFLOW CASES"
echo "========================================"
run_test "2147483648"
run_test "-2147483649"
run_test "999999999999999999999999999999999999999"

echo "========================================"
echo " INVALID INPUTS"
echo "========================================"
run_test "hello"
run_test "42ff"
run_test "42.0ff"
run_test "42.42.42"
run_test ""

echo "========================================"
echo " DONE"
echo "========================================"