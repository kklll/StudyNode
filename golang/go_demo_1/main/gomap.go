package main

import "fmt"

func main() {
	m := make(map[string]int)
	m["k1"] = 7
	m["k2"] = 13
	fmt.Println(m)

	v1 := m["k1"]
	fmt.Println("v1", v1)
	fmt.Println("len:", len(m))
	delete(m, "k2")
	fmt.Println(m)
	_, exi := m["k2"]
	fmt.Println(exi)

	n := map[string]int{"foo": 1, "bar": 2}
	fmt.Println(n)

}
