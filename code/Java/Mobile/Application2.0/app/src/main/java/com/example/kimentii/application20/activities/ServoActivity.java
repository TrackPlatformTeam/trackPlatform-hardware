package com.example.kimentii.application20.activities;

import android.app.Activity;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.support.v7.app.ActionBar;
import android.support.v7.app.AppCompatActivity;
import android.widget.Button;
import android.widget.TextView;

import com.example.kimentii.application20.R;
import com.example.kimentii.application20.connectors.BluetoothConnector;
import com.example.kimentii.application20.settings.Settings;
import com.example.kimentii.application20.wrappers.LanguageWrapper;

public class ServoActivity extends AppCompatActivity {

    private TextView connectionStateTextView;
    private BluetoothConnector bluetoothConnector;
    private Button upButton;
    private Button rightButton;
    private Button leftButton;
    private Button downButton;

    private void setLocaleLanguage() {
        if (bluetoothConnector != null && bluetoothConnector.isConnected()) {
            connectionStateTextView.setText(Settings.getInstance().getLanguageWrapper().
                    getViewString(LanguageWrapper.CONNECTED));
        } else {
            connectionStateTextView.setText(Settings.getInstance().getLanguageWrapper().
                    getViewString(LanguageWrapper.NO_CONNECTION));
        }
        upButton.setText(Settings.getInstance().getLanguageWrapper().
                getViewString(LanguageWrapper.UP_SERVO_BUTTON));
        rightButton.setText(Settings.getInstance().getLanguageWrapper().
                getViewString(LanguageWrapper.RIGHT_SERVO_BUTTON));
        leftButton.setText(Settings.getInstance().getLanguageWrapper().
                getViewString(LanguageWrapper.LEFT_SERVO_BUTTON));
        downButton.setText(Settings.getInstance().getLanguageWrapper().
                getViewString(LanguageWrapper.DOWN_SERVO_BUTTON));
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_servo);
        ActionBar actionBar = getSupportActionBar();
        actionBar.setHomeButtonEnabled(true);
        actionBar.setDisplayHomeAsUpEnabled(true);

        Handler handler = new Handler() {
            @Override
            public void handleMessage(Message msg) {
                super.handleMessage(msg);

            }
        };
        bluetoothConnector = BluetoothConnector.getInstance();
        bluetoothConnector.setHandler(handler);

        connectionStateTextView = (TextView) findViewById(R.id.connection_state_tv_servo_activity);
        upButton = (Button) findViewById(R.id.up_sero_button);
        rightButton = (Button) findViewById(R.id.right_servo_button);
        leftButton = (Button) findViewById(R.id.left_servo_button);
        downButton = (Button) findViewById(R.id.down_servo_button);
        setLocaleLanguage();


    }
}
