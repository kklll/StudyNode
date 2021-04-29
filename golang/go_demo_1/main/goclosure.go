package main

import "fmt"

func main() {
	nextInt := intseq()
	fmt.Println(nextInt())
	fmt.Println(nextInt())
	fmt.Println(nextInt())
	fmt.Println(nextInt())
	nextInt2 := intseq()
	fmt.Println(nextInt2())
	fmt.Println(nextInt2())

}

func intseq() func() int {
	i := 0
	return func() int {
		i++
		return i
	}
}
