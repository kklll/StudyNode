package main

import "fmt"

type Person struct {
	name string
	age  int
}

func main() {
	fmt.Println(Person{name: "张三", age: 13})
	fmt.Println(Person{name: "Alice", age: 30})
	fmt.Println(Person{name: "Alice2"})
	fmt.Println(Person{name: "Anna", age: 12})
	s := Person{name: "sean", age: 12}
	fmt.Println(s.name)
	sp := &s
	fmt.Println(sp.age)
	sp.age = 23
	fmt.Println(*sp)
	fmt.Println(*sp)
}
