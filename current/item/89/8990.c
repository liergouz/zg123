
// �Զ����ɣ�/make/item/make89b

inherit ITEM;

// ��������ʯʶ��
int is_diamond() { return 2; }

int get_item_color() { return 2; }

// ���������촦��
void create()
{
        set_name("���ʱ�ʯ��");
        set_picid_1(8900);
        set_picid_2(8900);
        set_unit("��");
        set_value(2000);
        set_level(20);
}

// ��������ȡ����
string get_desc() 
{ 
        return "һ���ṩ��ʯ��ʦ���ֽ�Ϊ��ʯ��ԭ��"; 
}
