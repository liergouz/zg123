
inherit TALISMAN;

// ��������Ч����
int get_active_rate() { return 90; }

// ��������Чʱ��
int get_time_interval() { return 480; }

// ����������ʶ��
int get_talisman_type() { return 7; }

// ���������촦��
void create()
{
        set_name( "������" );
        set_picid_1(9561);
        set_picid_2(9561);
        set_unit( "��" );

        set_level(3);
        set_value(20000);
        set_max_lasting(3099);

        setup();
}

// ��������ȡ����
string get_desc() 
{ 
        return "ѹ�ƶԷ�������ʹ����һ��ʱ����ʧȥЧ��";
}

// ��������ʹ�÷���
int is_usable_2() { return 1; }

// ������ʹ�÷���Ч��
int get_use_effect_2( object me, object who, string arg ) { return __DIR__ "9561" ->get_use_effect_2_callout( me, who, this_object(), arg ); }
