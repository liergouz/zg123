
// �Զ����ɣ�/make/item/make98a

inherit ITEM;
inherit "/inh/item/task";

// ���������촦��
void create()
{
        set_name("%s");
        set_picid_1(%d);
        set_picid_2(%d);
        set_unit("%s");
        set_value(%d);
}

// ��������ȡ����
string get_desc() 
{ 
        return "ʹ��������Ʒ"; 
}
