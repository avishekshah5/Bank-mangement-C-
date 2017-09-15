package com.avh.class1.fragement;


import android.content.Context;
import android.os.Bundle;
import android.support.annotation.Nullable;
import android.support.v4.app.Fragment;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import com.avh.class1.DatabaseHelperLocate;
import com.avh.class1.R;
import com.avh.class1.locationinfo;

/**
 * Created by AVSH SHAH on 2/22/2017.
 */

public class locationFragement extends Fragment {

    @Override
    public void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
    }
    DatabaseHelperLocate databaseHelperLocate1;
    Context context1;
    String id;
    @Nullable
    @Override
    public View onCreateView(LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {

        View view=inflater.inflate(R.layout.locationdetail1,null);
        id= getActivity().getIntent().getStringExtra("id");
        databaseHelperLocate1=new DatabaseHelperLocate(getActivity());
        locationinfo info=databaseHelperLocate1.getselectedlocation(id);

        TextView description =(TextView)view.findViewById(R.id.descriptioninfo);
        description.setText(info.description);

        TextView nview1=(TextView)view.findViewById(R.id.accomodationinfo);
        nview1.setText(info.accomodation);

        return view;
    }
}
