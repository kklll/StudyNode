import java.util.*;

/**
 * @ClassName InterpreterTest
 * @Deacription 面试题
 * @Author DeepBlue
 * @Date 2021/3/5 17:10
 * @Version 1.0
 **/
public class InterpreterTest {
    public static void main(String[] args) {
//        String s = "mov bx 2\n" +
//                "mov ax 5\n" +
//                "inc bx\n" +
//                "dec ax\n" +
//                "jnz ax -2\n" +
//                "dec ax ";
        String s="mov ax 10000\n" +
                "mov bx ax\n" +
                "dec bx\n" +
                "jnz bx -1\n" +
                "dec ax\n" +
                "jnz ax -4";
        String[] split = s.split("\n");
        ArrayList<String> statement = new ArrayList<>(Arrays.asList(split));
        long l = System.currentTimeMillis();
        exec(statement);
        System.out.println(System.currentTimeMillis()-l);
    }

    public static void exec(List<String> statement) {
        Map<String, Integer> vars = new HashMap<>();
        int pc = 0;
        while (pc < statement.size()) {
            String s = statement.get(pc);
            String[] s1 = s.split(" ");
            switch (s1[0]) {
                case "inc":
                    Integer val = vars.get(s1[1]);
                    vars.put(s1[1], val + 1);
                    pc++;
                    break;
                case "dec":
                    Integer val1 = vars.get(s1[1]);
                    vars.put(s1[1], val1 - 1);
                    pc++;
                    break;
                case "mov":
                    if (isNumeric(s1[2])) {
                        vars.put(s1[1], Integer.valueOf(s1[2]));
                    } else {
                        vars.put(s1[1], vars.get(s1[2]));
                    }
                    pc++;
                    break;
                case "jnz":
                    if (isNumeric(s1[1])) {
                        if (Integer.parseInt(s1[1]) != 0) {
                            pc += Integer.parseInt(s1[2]);
                        } else {
                            pc++;
                        }
                    } else {
                        if (vars.get(s1[1]) != 0) {
                            pc += Integer.parseInt(s1[2]);
                        } else {
                            pc++;
                        }
                    }
                    break;
            }
        }
        output(vars);
    }

    public static boolean isNumeric(String str) {
        for (int i = 0; i < str.length(); i++) {
            if (!Character.isDigit(str.charAt(i))) {
                return false;
            }
        }
        return true;
    }

    public static void output(Map<String, Integer> vars) {
        for (Map.Entry entry : vars.entrySet()) {
            System.out.println(entry.getKey() + " " + entry.getValue());
        }
    }
}
