package com.regyspecial.myapplication;
import android.app.*;
import android.support.v7.app.*;
import android.os.Bundle;
import android.view.View;
import android.widget.*;
import java.sql.*;
public class MainActivity extends Activity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.id.layout);
        LinearLayout layout=getContentViewById(R.id.layout);
        final Button PlayButton=getContentViewById(R.id.Play);
        PlayButton.setWidth(layout.getWidth()/2);
        PlayButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                PopupWindow PlayDialog=new PopupWindow();
                try {
                    Class.forName("com.sqlite.jdbc.Driver");
                    java.sql.Connection SQLiteConnection=DriverManager.getConnection("jdbc:sqlite://file://");
                    java.sql.PreparedStatement SQLQuery=SQLiteConnection.prepareStatement("select distinct name from User");
                    while(SQLQuery.execute()){
                        java.sql.ResultSet result=SQLQuery.getResultSet();
                        result.getString(1);
                    }
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        });
    }
}