package main

import "fmt"

func main() {
	nums := []int{1, 2, 3, 4}
	sum := 0
	fmt.Println(nums)
	for _, i := range nums {
		sum += i
	}
	fmt.Println("sum:", sum)
	for i, num := range nums {
		if num == 3 {
			fmt.Println("index=", i)
		}
	}
	kvs := map[string]string{"a": "apple", "b": "banana"}
	for k, v := range kvs {
		fmt.Println("key:", k, "value:", v)
	}
	for k := range kvs {
		fmt.Println(k)
	}
	for index, char := range "go" {
		fmt.Printf("index:%d,value:%c\n", index, char)
	}
}
