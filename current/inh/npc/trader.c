
private static int BuyRate;             // ����ָ��
private static int SellRate;            // ����ָ��

// ����������ʶ��
int is_trader() { return 1; }

// ��������ȡ����ָ��
int get_buy_rate() { return BuyRate; }

// ��������������ָ��
int set_buy_rate( int rate ) 
{ 
        if( rate < 0 ) rate = 0;
        else if( rate > 1000 ) rate = 1000;
        return BuyRate = rate; 
}

// ��������������ָ��
int add_buy_rate( int rate ) { return BuyRate += rate; }

// ��������ȡ����ָ��
int get_sell_rate() { return SellRate; }

// ��������������ָ��
int set_sell_rate( int rate ) 
{ 
        if( rate < 0 ) rate = 0;
        else if( rate > 1000 ) rate = 1000;
        return SellRate = rate; 
}

// ��������������ָ��
int add_sell_rate( int rate ) { return SellRate += rate; }
