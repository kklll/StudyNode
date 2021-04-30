package main

import (
	"fmt"
	"io/ioutil"
	"os"
	"path/filepath"
)

func Check2(err error) {
	if err != nil {
		panic(err)
	}
}
func main() {
	f, err := ioutil.TempFile("", "sample")
	Check2(err)
	fmt.Println("temporary file name:", f.Name())
	defer os.Remove(f.Name())
	_, err = f.Write([]byte{1, 2, 3, 4})
	Check2(err)
	dname, err := ioutil.TempDir("", "sampleDir")
	fmt.Println("temp dir name", dname)
	defer os.RemoveAll(dname)
	fname := filepath.Join(dname, "file1")
	err = ioutil.WriteFile(fname, []byte{1, 2, 3}, 0755)
	Check2(err)
}
