package com.avh.class1;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.webkit.WebView;
import android.webkit.WebViewClient;
import android.widget.ProgressBar;

public class recommendactivity extends AppCompatActivity {
    WebView webview;
    ProgressBar progress;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.recommend);
        webview=(WebView)findViewById(R.id.webview);
        progress=(ProgressBar)findViewById(R.id.progress);
        webview.loadUrl("http://tourismnepal.net/");
        webview.setWebViewClient(new WebViewClient(){
            @Override
            public void onPageFinished(WebView view, String url) {
                super.onPageFinished(view, url);
                progress.setVisibility(view.GONE);
            }
        });

           webview.getSettings().setJavaScriptEnabled(true);
    }
}
