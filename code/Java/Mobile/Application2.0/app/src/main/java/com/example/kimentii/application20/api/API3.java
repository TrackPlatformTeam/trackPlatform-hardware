package com.example.kimentii.application20.api;

public class API3 implements API {
    @Override
    public byte[] getConnectCommand() {
        return new byte[0];
    }

    @Override
    public byte[] getDisconnectCommand() {
        return new byte[0];
    }

    @Override
    public byte[] getMoveForwardCommand() {
        return new byte[0];
    }

    @Override
    public byte[] getMoveRightCommand() {
        return new byte[0];
    }

    @Override
    public byte[] getMoveLeftCommand() {
        return new byte[0];
    }

    @Override
    public byte[] getMoveBackCommand() {
        return new byte[0];
    }

    @Override
    public byte[] getStopCommand() {
        return new byte[0];
    }

    @Override
    public byte[] getTurnUpServoCommand() {
        return new byte[0];
    }

    @Override
    public byte[] getTurnRightServoCommand() {
        return new byte[0];
    }

    @Override
    public byte[] getTurnLeftServoCommand() {
        return new byte[0];
    }

    @Override
    public byte[] getTurnDownServoCommand() {
        return new byte[0];
    }

    @Override
    public byte[] getInfoFromDistanceSensorCommand(int i) {
        return new byte[0];
    }

    @Override
    public byte[] getInfoFromLineSensorCommand(int i) {
        return new byte[0];
    }

    @Override
    public byte[] getChangeApiCommand(int i) {
        return new byte[0];
    }
}
