package com.avh.class1.fragement;

import android.content.Context;
import android.os.Bundle;
import android.support.annotation.Nullable;
import android.support.v4.app.Fragment;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;

import com.avh.class1.DatabaseHelperLocate;
import com.avh.class1.R;
import com.avh.class1.addlocationactivity;
import com.avh.class1.locationinfo;

import static android.R.attr.description;

/**
 * Created by AVSH SHAH on 2/17/2017.
 */

public class topFragement extends Fragment {

      @Override
    public void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);


    }
    DatabaseHelperLocate databaseHelper12;
    String id;
    @Nullable
    @Override
    public View onCreateView(LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {

        View view=inflater.inflate(R.layout.locationdetail,null);
        id= getActivity().getIntent().getStringExtra("id");

        databaseHelper12=new DatabaseHelperLocate(getActivity());

        locationinfo info=databaseHelper12.getselectedlocation(id);

        ImageView image=(ImageView)view.findViewById(R.id.imge1);

        image.setImageBitmap(addlocationactivity.getBitmap(info.image1));

        ImageView image2=(ImageView)view.findViewById(R.id.imge2);

        image2.setImageBitmap(addlocationactivity.getBitmap(info.image2));
        TextView desc=(TextView)view.findViewById(R.id.locationinfo);
        desc.setText(info.locationname);
        TextView nameview3=(TextView)view.findViewById(R.id.addressinfo1);
        nameview3.setText(info.address);


        return view;
    }


}
