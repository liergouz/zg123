
inherit TALISMAN;

// ��������Ч����
int get_active_rate() { return 100; }

// ����������ʶ��
int get_talisman_type() { return 6; }

// ���������촦��
void create()
{
        set_name( "������" );
        set_picid_1(9551);
        set_picid_2(9551);
        set_unit( "��" );

        set_level(2);
        set_value(10000);
        set_max_lasting(3099);

        setup();
}

// ��������ȡ����
string get_desc() 
{ 
        return "�����Լ�����ǰ������ָ������";
}

// ��������ʹ�÷���
int is_usable_2() { return 1; }

// ������ʹ�÷���Ч��
int get_use_effect_2( object me, object who, string arg ) { return __DIR__ "9551" ->get_use_effect_2_callout( me, who, this_object(), arg ); }
