package main

import (
	"fmt"
	"sort"
)

type bylength []string

func (a bylength) Len() int {
	return len(a)
}

func (a bylength) Swap(i, j int) {
	a[i], a[j] = a[j], a[i]
}

func (a bylength) Less(i, j int) bool {
	return len(a[i]) < len(a[j])
}
func main() {
	fruits := []string{"apple", "banana", "pear"}
	sort.Sort(bylength(fruits))
	fmt.Println(fruits)
}
