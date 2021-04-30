package main

import (
	"bufio"
	"fmt"
	"io"
	"io/ioutil"
	"os"
)

func Check(e error) {
	if e != nil {
		panic(e)
	}
}

func main() {
	data, err := ioutil.ReadFile("test.txt")
	Check(err)
	fmt.Println(string(data))

	f, err := os.Open("test.txt")
	Check(err)
	defer func(f *os.File) {
		err := f.Close()
		if err != nil {
			panic(err)
		}
	}(f)
	b := make([]byte, 5)
	n1, err := f.Read(b)
	Check(err)
	fmt.Printf("read %d bytes content %s\n", n1, string(b))

	o2, err := f.Seek(6, 0)
	Check(err)
	b2 := make([]byte, 2)
	da, err := f.Read(b2)
	fmt.Printf("read %d bytes @ offset:%d\n", da, o2)

	o3, err := f.Seek(6, 0)
	Check(err)
	b3 := make([]byte, 2)
	n3, err := io.ReadAtLeast(f, b3, 2)
	Check(err)
	fmt.Printf("%d bytes @ %d: %s\n", n3, o3, string(b3))

	_, err = f.Seek(0, 0)
	Check(err)

	r4 := bufio.NewReader(f)
	b4, err := r4.Peek(5)
	Check(err)
	fmt.Printf("5 bytes: %s\n", string(b4))
}
