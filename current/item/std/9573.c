
inherit TALISMAN;

// ��������Ч����
int get_active_rate() { return 80; }

// ����������ʶ��
int get_talisman_type() { return 8; }

// ���������촦��
void create()
{
        set_name( "����ľ��" );
        set_picid_1(9571);
        set_picid_2(9571);
        set_unit( "ֻ" );

        set_level(3);
        set_value(20000);
        set_max_lasting(1899);

        setup();
}

// ��������ȡ����
string get_desc() 
{ 
        return "ʹ�ȴ���Ԯ���������ֱ�Ӹ���൱�ڡ��Զ����";
}

// ��������ʹ�÷���
int is_usable_2() { return 1; }

// ������ʹ�÷���Ч��
int get_use_effect_2( object me, object who, string arg ) { return __DIR__ "9571" ->get_use_effect_2_callout( me, who, this_object(), arg ); }
