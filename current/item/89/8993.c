
// �Զ����ɣ�/make/item/make89b

inherit ITEM;

// ��������ʯʶ��
int is_diamond() { return 2; }

int get_item_color() { return 2; }

// ���������촦��
void create()
{
        set_name("���±�ʯ��");
        set_picid_1(4108);
        set_picid_2(4108);
        set_unit("��");
        set_value(3500);
        set_level(80);
}

// ��������ȡ����
string get_desc() 
{ 
        return "һ���ṩ��ʯ��ʦ���ֽ�Ϊ��ʯ��ԭ��"; 
}
