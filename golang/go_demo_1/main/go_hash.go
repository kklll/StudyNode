package main

import (
	"crypto/sha1"
	"fmt"
)

func main() {
	s := "sha1 this string"
	h := sha1.New()
	h.Write([]byte(s))
	res := h.Sum(nil)
	fmt.Println(s)
	fmt.Printf("%x\n", res)
}
