package main

import (
	"fmt"
	"os"
)

func main() {
	//panic("a problem")
	_, error := os.Create("/os/sss")
	if error != nil {
		fmt.Println(error.Error())
		panic("文件创建失败")
	}
}
