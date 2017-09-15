package com.avh.class1.fragement;

import android.content.Context;
import android.os.Bundle;
import android.support.annotation.Nullable;
import android.support.v4.app.Fragment;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import com.avh.class1.DatabaseHelper;
import com.avh.class1.DatabaseHelperLocate;
import com.avh.class1.R;
import com.avh.class1.locationinfo;

/**
 * Created by AVSH SHAH on 2/17/2017.
 */


public class bottomFragement extends Fragment {

    @Override
    public void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
    }
DatabaseHelperLocate databasehelper2;
    String id;

    @Nullable
    @Override
    public View onCreateView(LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {

        View view=inflater.inflate(R.layout.locationdetail2,null);
        id= getActivity().getIntent().getStringExtra("id");
        databasehelper2=new DatabaseHelperLocate(getActivity());
        locationinfo info=databasehelper2.getselectedlocation(id);
        TextView nview=(TextView)view.findViewById(R.id.featureinfo);
        nview.setText(info.feature);
        TextView nview2=(TextView)view.findViewById(R.id.routeinfo);
        nview2.setText(info.route);
        TextView nview3=(TextView)view.findViewById(R.id.addedinfo);
        nview3.setText(info.addedby);
        return view;
    }
}
