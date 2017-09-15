package com.avh.class1;

import android.support.v4.app.Fragment;
import android.support.v4.app.FragmentManager;
import android.support.v4.app.FragmentPagerAdapter;
import android.support.v4.app.FragmentTransaction;
import android.support.v4.view.ViewPager;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;

import com.avh.class1.fragement.bottomFragement;
import com.avh.class1.fragement.locationFragement;
import com.avh.class1.fragement.topFragement;

public class Fragementexample extends AppCompatActivity {
    ViewPager viewpager;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.fragementexample);
        viewpager=(ViewPager)findViewById(R.id.viewpager);
        viewpager.setAdapter(new viewpageradapter(getSupportFragmentManager()));


    }
    public class viewpageradapter extends FragmentPagerAdapter{

        public viewpageradapter(FragmentManager fm) {
            super(fm);
        }

        @Override
        public Fragment getItem(int position) {
            switch (position) {
                case 0:
                 return new topFragement();

                case 1:
                    return  new locationFragement();






            }
            return  new bottomFragement();
        }

        @Override
        public int getCount() {
            return 3;
        }
    }
}
