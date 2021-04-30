package main

import (
	"fmt"
	"path/filepath"
	"strings"
)

func main() {
	p := filepath.Join("下载", "视频", "我的视频")
	fmt.Println(p)
	fmt.Println(filepath.Join("dir1//", "filename"))
	fmt.Println(filepath.Join("dir1/../dir1", "filename"))
	fmt.Println("Dir(p):", filepath.Dir(p))
	fmt.Println("Base(p):", filepath.Base(p))
	fmt.Println(filepath.IsAbs("dir/file"))
	fmt.Println(filepath.IsAbs("/dir/file"))
	filename := "test.json"
	ext := filepath.Ext(filename)
	fmt.Println(ext)
	fmt.Println(strings.TrimSuffix(filename, ext))

	//返回两个路径的相对路径，如果找不到的话返回错误
	rel, err := filepath.Rel("a/b", "a/b/t/file")
	if err != nil {
		panic(err)
	}
	fmt.Println(rel)
	rel, err = filepath.Rel("a/b", "a/c/t/file")
	if err != nil {
		panic(err)
	}
	fmt.Println(rel)
}
