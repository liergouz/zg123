
inherit ITEM;
inherit USABLE;

int get_item_color() { return 2; }
// ��������Ҫȷ������
int confirm_sell_item() { return 1; }

// ���������촦��
void create()
{
        set_name( "�ϲε�" );
        set_picid_1(9167);
        set_picid_2(9167);
        set_unit( "��" );
        set_value(50);
}

// ��������ȡ����
int get_item_value() {return 8 ;}
int get_item_value_2() {return 8 ;}
string get_desc() 
{ 
        return "�� 20000 ��Ǳ�ܣ�ʹ��ʱ������1 ��";
}

// ������ʹ��Ч��
int get_use_effect( object me ) { return __FILE__ ->get_use_effect_callout(me); }

// ������ʹ��Ч��(���߸���)
int get_use_effect_callout( object me )
{
	if (me->get_potential()+20000>me->get_max_potential())
	{
		
                send_user( me, "%c%s", '!', "���Ǳ���Ѿ��ӽ����ޣ���ʱ����ʹ���ϲε���" );
                return 0;		
	}	
      	if( gone_time( me->get_time("eat_zs") ) < 1 )
        {
                send_user( me, "%c%s", '!', sprintf("�����ϲε�����Ⱥ�%d��", 30 - gone_time( me->get_time("eat_zs") ) ) );
                return 0;
        }        
	me->set_time( "eat_zs", time() );  
        me->add_potential(20000);
        return 1;
}
