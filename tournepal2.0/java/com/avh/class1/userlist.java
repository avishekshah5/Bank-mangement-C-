package com.avh.class1;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.widget.LinearLayout;
import android.widget.TextView;

import java.util.ArrayList;

public class userlist extends AppCompatActivity {
    LinearLayout container;
    DatabaseHelper databaseHelper;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.userlist);
        container=(LinearLayout)findViewById(R.id.container);
        databaseHelper=new DatabaseHelper(this);
        populatedata();
    }
    public void populatedata(){
        ArrayList<userinfo>list=databaseHelper.getUserlist();
        for(int i=0;i<list.size();i++){
            final userinfo info=list.get(i);
            TextView textview=new TextView(this);
            textview.setText(
            info.username+" ,"+info.address+"\n");
            View view= LayoutInflater.from(this).inflate(R.layout.itemlayout,null);
            TextView username,address,phone;
            username=(TextView)view.findViewById(R.id.username);
            address=(TextView)view.findViewById(R.id.address);

            username.setText(info.username);
            address.setText(info.address);
            view.setOnClickListener(new View.OnClickListener(){

                @Override
                public void onClick(View v) {
                    Intent intent=new Intent(userlist.this,userdetail.class);
                    intent.putExtra("id",info.id);
                    startActivity(intent);
                }
            });


            container.addView(view);

        }
    }

}
