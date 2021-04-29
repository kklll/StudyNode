package main

import (
	"fmt"
	"os"
)

func main() {
	file := createFile("test.txt")
	defer closeFile(file)
	writeFile(file)
}
func createFile(filename string) *os.File {
	fmt.Println("creating....")
	f, error := os.Create(filename)
	if error != nil {
		panic("无法创建文件！")
	}
	return f
}

func writeFile(file *os.File) {
	fmt.Println("waiting")
	_, err := fmt.Fprintln(file, "hello file")
	if err != nil {
		return
	}
}
func closeFile(file *os.File) {
	fmt.Println("closing")
	err := file.Close()
	if err != nil {
		os.Exit(1)
	}
}
