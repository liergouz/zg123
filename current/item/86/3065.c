
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit NECK;

// ��������������
int get_family() { return 3; }

// ���������촦��
void create()
{
        set_name("��ľ����");
        set_picid_1(8608);
        set_picid_2(8608);

        set_level(65);
        set_value(38000);
        set_max_lasting(7999);
        set("cp", 0);
        set("pp", 60);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��ľ����";
}
