package main

import (
	"fmt"
	"strconv"
)

func main() {
	f, _ := strconv.ParseFloat("1.23344", 64)
	fmt.Println(f)
	i, _ := strconv.ParseInt("123", 0, 64)
	fmt.Println(i)
	d, _ := strconv.ParseInt("0x1c8", 0, 64)
	fmt.Println(d)
	u, _ := strconv.ParseUint("789", 0, 64)
	fmt.Println(u)
	k, _ := strconv.Atoi("123")
	fmt.Println(k)
	_, e := strconv.Atoi("wat")
	fmt.Println(e)
}
