
// �Զ����ɣ�/make/item/make49

inherit ITEM;
%s  inherit COMBINED;

// ��������������
%s  int get_max_combined() { return %d; }

// ���������촦��
void create()
{
        set_name("%s");
        set_picid_1(%d);
        set_picid_2(%d);
        set_unit("%s");
        set_value(%d);
%s      set_amount(1);
}

// ��������ȡ����
string get_desc() 
{ 
        return "%s";
}
