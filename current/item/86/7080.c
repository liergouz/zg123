
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit NECK;

// ��������������
int get_family() { return 7; }

// ���������촦��
void create()
{
        set_name("��ϼ����");
        set_picid_1(8650);
        set_picid_2(8650);

        set_level(80);
        set_value(62000);
        set_max_lasting(5799);
        set("cp", 150);
        set("pp", 90);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��ϼ����";
}
