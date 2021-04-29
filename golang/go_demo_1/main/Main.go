package main

import "fmt"

func main() {
	ar := []byte{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'}
	var a, b []byte
	a = ar[0:3]
	b = ar[1:2]
	fmt.Println(a)
	fmt.Println(b)
	ar[1] = 'c'
	fmt.Println(a)
	fmt.Println(b)
}
