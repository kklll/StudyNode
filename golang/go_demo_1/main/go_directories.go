package main

import (
	"fmt"
	"io/ioutil"
	"os"
	"path/filepath"
)

//go的文件目录
func main() {
	err := os.Mkdir("subdir", 0755)
	Check(err)
	defer os.RemoveAll("subdir")
	createEmptyFile := func(name string) {
		d := []byte("")
		Check(ioutil.WriteFile(name, d, 0644))
	}
	createEmptyFile("subdir/file1")
	err = os.MkdirAll("subdir/parent/child", 0755)
	Check(err)
	createEmptyFile("subdir/parent/file2")
	createEmptyFile("subdir/parent/file3")
	createEmptyFile("subdir/parent/child/file4")
	c, err := ioutil.ReadDir("subdir/parent")
	fmt.Println("listing subdir/parent")
	for _, entry := range c {
		fmt.Println(" ", entry.Name(), entry.IsDir())
	}
	err = os.Chdir("subdir/parent/child")
	Check(err)
	c, err = ioutil.ReadDir(".")
	Check(err)
	fmt.Println("listing subdir/parent/child")
	for _, entry := range c {
		fmt.Println(" ", entry.Name(), entry.IsDir())
	}

	err = os.Chdir("../../../")
	Check(err)
	fmt.Println("visiting subdir")
	err = filepath.Walk("subdir", visit)
}
func visit(path string, info os.FileInfo, err error) error {
	if err != nil {
		panic(err)
	}
	fmt.Println(" ", path, info.IsDir())
	return nil
}
