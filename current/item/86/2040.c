
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit NECK;

// ��������������
int get_family() { return 2; }

// ���������촦��
void create()
{
        set_name("��ʯ����");
        set_picid_1(8610);
        set_picid_2(8610);

        set_level(40);
        set_value(20500);
        set_max_lasting(7299);
        set("cp", 0);
        set("pp", 45);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��ʯ����";
}
