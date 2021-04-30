package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

//行过滤器（line filter） 是一种常见的程序类型，
//它读取 stdin 上的输入，对其进行处理，然后将处理结果打印到 stdout。
//grep 和 sed 就是常见的行过滤器。
func main() {

	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		fmt.Println(strings.ToUpper(scanner.Text()))
	}
	if err := scanner.Err(); err != nil {
		fmt.Fprintln(os.Stderr, "error:", err)
		os.Exit(1)
	}
}
