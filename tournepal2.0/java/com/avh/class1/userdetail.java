package com.avh.class1;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

public class userdetail extends AppCompatActivity {
    String id;
    DatabaseHelper databaseHelper;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.userdetail);
        id=getIntent().getStringExtra("id");
        databaseHelper=new DatabaseHelper(this);
        userinfo info=databaseHelper.getselecteduserinfo(id);
        TextView nameview=(TextView)findViewById(R.id.nameinfo);
        nameview.setText(info.username);
        TextView passview=(TextView)findViewById(R.id.passinfo);
        passview.setText(info.password);
        TextView nameview2=(TextView)findViewById(R.id.emailinfo);
        nameview2.setText(info.email);
        TextView nameview3=(TextView)findViewById(R.id.phoneinfo);
        nameview3.setText(info.phone);
        TextView nameview4=(TextView)findViewById(R.id.addressinfo);
        nameview4.setText(info.address);
        TextView nameview5=(TextView)findViewById(R.id.genderinfo);
        nameview5.setText(info.gender);
        TextView nameview6=(TextView)findViewById(R.id.dobinfo);
        nameview6.setText(info.dob);

    }
}
