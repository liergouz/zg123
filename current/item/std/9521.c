
inherit TALISMAN;

// ��������Ч����
int get_active_rate() { return 10; }

// ����������ʶ��
int get_talisman_type() { return 3; }

// ���������촦��
void create()
{
        set_name( "�����" );
        set_picid_1(9521);
        set_picid_2(9521);
        set_unit( "��" );

        set_level(1);
        set_value(5000);
        set_max_lasting(15099);

        setup();
}

// ��������ȡ����
string get_desc() 
{ 
        return "������ʱ����ʹ�Է�ѣ��";
}
