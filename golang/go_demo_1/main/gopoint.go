package main

import "fmt"

func main() {
	a := 2
	zeroVal(a)
	fmt.Println(a)
	zeroPtr(&a)
	fmt.Println(a)
	fmt.Println(&a)
}
func zeroVal(a int) {
	a = 0
}

func zeroPtr(a *int) {
	*a = 0
}
