inherit ITEM;
inherit COMBINED;

int get_item_color() { return 1; }

// ���������촦��
void create()
{
        set_name("װ�Ż�С��������«");
        set_picid_1(4271);
        set_picid_2(4271);
	set_amount(1);
        set_value(50);
}

// ��������ȡ����
string get_desc() 
{ 
        return "����ĺ�«��\n����װ����ͼ͵�����ϵĻ�С��\n�����������ϲ�����ѵ�ɡ�"; 
}
