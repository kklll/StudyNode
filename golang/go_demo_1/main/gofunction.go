package main

import "fmt"

func main() {
	i := plus(1, 2)
	fmt.Println("1+2=", i)
	j := plusplus(1, 2, 3)
	fmt.Println("1+2+3=", j)
	a, _ := values()
	fmt.Println(a)
	x, y := values()
	fmt.Println(x, y)
	sum := sum(1, 2, 1, 3, 4, 5, 6, 7, 8, 9)
	fmt.Println(sum)
}
func plus(a int64, b int64) int64 {
	return a + b
}

func plusplus(a, b, c int64) int64 {
	return a + b + c
}

func values() (int, int) {
	return 1, 2
}

func sum(a ...int64) int64 {
	fmt.Println(a, " ")
	var total int64 = 0
	for _, value := range a {
		total += value
	}
	return total
}
