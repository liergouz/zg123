
private int Con;                 // ���ǣ�����   Constitution
private int Spi;                 // ��������   Spirituality
private int Str;                 // ����         Strength
private int Cps;                 // ����������   Composure
private int Dex;                 // ���ݣ�����   Dexterity

// -------------------------------------------------------------

// ��������ȡ��������
int get_con() { return Con; }

// ��������ȡ��������
int get_spi() { return Spi; }

// ��������ȡ��������
int get_str() { return Str; }

// ��������ȡ��������
int get_cps() { return Cps; }

// ��������ȡ��������
int get_dex() { return Dex; }

// ������������������
int set_con( int gift ) { return Con = gift; }

// ���������þ�������
int set_spi( int gift ) { return Spi = gift; }

// ������������������
int set_str( int gift ) { return Str = gift; }

// ������������������
int set_cps( int gift ) { return Cps = gift; }

// ������������������
int set_dex( int gift ) { return Dex = gift; }

// ������������������
int add_con( int gift ) { return set_con( Con + gift ); }

// ����������������
int add_spi( int gift ) { return set_spi( Spi + gift ); }

// ������������������
int add_str( int gift ) { return set_str( Str + gift ); }

// ������������������
int add_cps( int gift ) { return set_cps( Cps + gift ); }

// ������������������
int add_dex( int gift ) { return set_dex( Dex + gift ); }
