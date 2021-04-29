package main

import "fmt"

func main() {
	i := fact(7)
	fmt.Println(i)
}

func fact(n int) int {
	if n > 1 {
		return n * fact(n-1)
	} else {
		return 1
	}
}
