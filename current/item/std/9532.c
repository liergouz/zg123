
inherit TALISMAN;

// ��������Ч����
int get_active_rate() { return 75; }

// ����������ʶ��
int get_talisman_type() { return 4; }

// ���������촦��
void create()
{
        set_name( "��Ϭ��" );
        set_picid_1(9531);
        set_picid_2(9531);
        set_unit( "��" );

        set_level(2);
        set_value(10000);
        set_max_lasting(10099);

        setup();
}

// ��������ȡ����
string get_desc() 
{ 
        return "���Ͷ����ж��ѡ�ͬ���ɵĳ�Ա���������Լ����";
}

// ��������ʹ�÷���
int is_usable_2() { return 1; }

// ������ʹ�÷���Ч��
int get_use_effect_2( object me, object who, string arg ) { return __DIR__ "9531" ->get_use_effect_2_callout( me, who, this_object(), arg ); }

// ���������շ���Ч��
int accept_use_effect_2( object me, object who ) { return __DIR__ "9531" ->accept_use_effect_2_callout(me, who); }
