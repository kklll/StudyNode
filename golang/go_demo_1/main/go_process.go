package main

import (
	"fmt"
	"golang.org/x/text/encoding/simplifiedchinese"
	"os/exec"
)

func ConvertGBK2Str(gbkStr string) string {
	//将GBK编码的字符串转换为utf-8编码
	ret, err := simplifiedchinese.GBK.NewDecoder().String(gbkStr)
	if err != nil {
		panic(err)
	}
	return ret //如果转换失败返回空字符串

	//如果是[]byte格式的字符串，可以使用Bytes方法
	b, err := simplifiedchinese.GBK.NewDecoder().Bytes([]byte(gbkStr))
	if err != nil {
		panic(err)
	}
	return string(b)
}

func main() {
	dirCmd := exec.Command("tree")
	output, err := dirCmd.Output()
	if err != nil {
		panic(err)
	}
	fmt.Println(ConvertGBK2Str(string(output)))
}
