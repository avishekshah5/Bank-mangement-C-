package com.avh.class1;

import android.content.Context;
import android.content.Intent;
import android.support.annotation.NonNull;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.ImageView;
import android.widget.TextView;

import java.util.ArrayList;

/**
 * Created by AVSH SHAH on 2/16/2017.
 */

public class locationlistadapter extends ArrayAdapter<locationinfo> {

    Context context1;
    DatabaseHelperLocate databaseHelperLocate;

    public locationlistadapter(Context context, ArrayList<locationinfo>list) {
        super(context,0,list);
        this.context1 = context;
        databaseHelperLocate= new DatabaseHelperLocate(context1);
    }

    @NonNull
    @Override
    public View getView(int position, View convertView, ViewGroup parent) {
        final locationinfo info = getItem(position);
        View view = LayoutInflater.from(context1).inflate(R.layout.locationitem, null);
        ImageView image1;
        TextView locationname, address, feature, addedby;
        locationname = (TextView) view.findViewById(R.id.locationname);
        address = (TextView) view.findViewById(R.id.address);
        feature = (TextView) view.findViewById(R.id.feature);
        addedby = (TextView) view.findViewById(R.id.updatedby);
        image1 = (ImageView) view.findViewById(R.id.image1);

        locationname.setText(info.locationname);
        address.setText(info.address);
        feature.setText(info.feature);
        addedby.setText(info.addedby);
        image1.setImageBitmap(addlocationactivity.getBitmap(info.image1));
        view.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent i = new Intent (context1,Fragementexample.class);
                i.putExtra("id",info.id);

                context1.startActivity(i);
            }
        });



        return view;
    }
}
