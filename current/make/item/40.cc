
// �Զ����ɣ�/make/item/make30

inherit ITEM;
%s  inherit COMBINED;

// ��������ȡװ����ɫ����ɫ
//int get_item_color() { return 0; }

// ��������������
%s  int get_max_combined() { return %d; }

// ���������촦��
void create()
{
        set_name("%s");
        set_picid_1(%d);
        set_picid_2(%d);
        set_value(%d);
%s      set_amount(1);
}

// ��������ȡ����
string get_desc() 
{ 
        return "%s"; 
}
