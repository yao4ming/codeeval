import java.io.*;
import java.util.*;

import org.json.simple.JSONArray;
import org.json.simple.JSONObject;
import org.json.simple.JSONValue;

/*
Uses JSON.simple library
*/
public class Main {

    public static void main(String[] args) {

        File file = new File(args[0]);
        BufferedReader in;
        String line;
        try {
            in = new BufferedReader(new FileReader(file));
            while ((line = in.readLine()) != null) {
                Object obj = JSONValue.parse(line);
                JSONObject jsonObject = (JSONObject) obj;
                JSONObject menu = (JSONObject) jsonObject.get("menu");
                JSONArray items = (JSONArray) menu.get("items");
                Iterator item = items.iterator();
                long sumId = 0;
                while (item.hasNext()) {
                    JSONObject label = (JSONObject) item.next();
                    if (label != null && label.containsKey("label")) {
                        sumId += (long) label.get("id");
                    }
                }
                System.out.println(sumId);
            }

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}