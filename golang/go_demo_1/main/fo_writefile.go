package main

import (
	"bufio"
	"fmt"
	"io/ioutil"
	"os"
)

func main() {
	//IOUtil的写入方法
	d1 := []byte("hello\ngo\n")
	err := ioutil.WriteFile("test.txt", d1, os.ModeAppend)
	Check(err)
	//OS的写入方法
	f, err := os.Create("test02.txt")
	Check(err)
	defer func(f *os.File) {
		err := f.Close()
		if err != nil {
			panic(err)
		}
	}(f)

	d2 := []byte{115, 110, 109, 110, 10}
	len2, err := f.Write(d2)
	fmt.Println("write: ", len2, "byte data")
	n3, err := f.WriteString("我的string-.-\n")
	Check(err)
	fmt.Println("write: ", n3, "byte data")
	err2 := f.Sync()
	Check(err2)
	//带缓冲区的写入方法
	w := bufio.NewWriter(f)
	n4, err := w.WriteString("buffered\n")
	Check(err)
	fmt.Println("write: ", n4, "byte data")
}
