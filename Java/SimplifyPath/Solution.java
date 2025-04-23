/*
LeetCode 71. Simplify Path

You are given an absolute path for a Unix-style file system, which always begins with a slash '/'. Your task is to transform this absolute path into its simplified canonical path.

Example 1:
    Input: path = "/home/"
    Output: "/home"

Example 2:
    Input: path = "/home//foo/"
    Output: "/home/foo"

Example 3:
    Input: path = "/home/user/Documents/../Pictures"
    Output: "/home/user/Pictures"
*/

import java.util.List;
import java.util.ArrayList;

class Solution {

    public static String simplifyPath(String path) {

        // create a list to store all the directories that will be in the simplified path
        List<String> directoriesSimplified = new ArrayList<String>();

        // splitting the string remove any duplicate slash characters
        String[] directories = path.split("/");
        for (int i = 0; i < directories.length; i++) {

            // get current directory from our string split
            String curDir = directories[i];
            
            // if the current directory is a blank string, or is a period, we don't need it
            if (curDir.length() < 1 || curDir.equals(".")) continue;

            // if the current directory is a double period, we need to get rid of the last thing in our list (if there is anything)
            if (curDir.equals("..")) {
                if (directoriesSimplified.size() >= 1) directoriesSimplified.remove(directoriesSimplified.size() - 1);
                continue;
            }
            
            // if we made it this far, the current directory can be added to our list
            directoriesSimplified.add(curDir);
        }

        // go through our directoriesSimplified list and make a path string out of it
        StringBuilder simplePath = new StringBuilder("/");
        for (int i = 0; i < directoriesSimplified.size(); i++) {
            simplePath.append(directoriesSimplified.get(i));
            if (i + 1 < directoriesSimplified.size()) simplePath.append("/");
        }
        return simplePath.toString();
    }

    public static void main(String[] args) {

        String input = "/.../a/../b/c/../d/./";
        String output = simplifyPath(input);
        System.out.println("result: " + output);
    }
}