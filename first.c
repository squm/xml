#include <libxml/parser.h>
#include <libxml/xmlwriter.h>
#include <libxml/tree.h>

#include	<stdio.h>

#define MY_ENCODING "UTF-8"

typedef const unsigned char* const goodCast;
#define	GOOD_CAST (goodCast)

#define xmlNC(node, name, data) xmlNewChild((node), NULL, GOOD_CAST (name), GOOD_CAST (data))

int
main() {
  goodCast root_element = (goodCast) "behemoth";

  xmlNodePtr node_root, node_next;
  xmlDocPtr doc;
  xmlChar *xmlbuff;
  int buffersize;
  // int rc;
  //  xmlChar *tmp;

  // rc = xmlTextWriterStartDocument(writer, NULL, MY_ENCODING, NULL);

  doc = xmlNewDoc(GOOD_CAST XML_DEFAULT_VERSION);
  // GOOD_CAST "standalone", GOOD_CAST "yes");

  node_root = xmlNewDocNode(doc, NULL, root_element, NULL);

  xmlNewProp(node_root, GOOD_CAST "type", GOOD_CAST "white");

  xmlDocSetRootElement(doc, node_root);

  xmlCreateIntSubset(doc, root_element, NULL, GOOD_CAST "behemoth.dtd");

  xmlNC(node_root, "Date", "");
  xmlNC(node_root, "DocumentN", "123");
  xmlNC(node_root, "Time", "");

  node_next = xmlNC(node_root, "Bear", NULL);

  xmlNC(node_next, "Address", "New Zealand");
  xmlNC(node_next, "Colour", "");

  node_next = xmlNC(node_root, "Giraffe", NULL);

  xmlNC(node_next, "Height", NULL);
  xmlNC(node_next, "Mood", "awake, aroused");

  node_next = xmlNC(node_root, "Zebra", NULL);

  xmlNC(node_next, "ColourOne", "white");
  xmlNC(node_next, "ColourTwo", "black");
  xmlNC(node_next, "Name", "");


#if 0
  /* 
   * xmlNewProp() creates attributes, which is "attached" to an node.
   * It returns xmlAttrPtr, which isn't used here.
   */
  // node =
  // xmlNewChild(root_node, NULL, GOOD_CAST "node3",
  // GOOD_CAST "this node has attributes");

  // xmlTextWriterPtr writer;
  // writer = xmlNewTextWriterTree(doc, node, 0);

  /* Start the document with the xml default for the version,
   * encoding ISO 8859-1 and the default for the standalone
   * declaration. */
  // xmlTextWriterStartDocument(writer, NULL, MY_ENCODING, NULL);

  // xmlTextWriterStartElement(writer, GOOD_CAST "STARTELEMENT");

  // xmlTextWriterWriteElement(writer, GOOD_CAST "one", GOOD_CAST "");
  // xmlTextWriterWriteElement(writer, GOOD_CAST "two", NULL);

  // xmlTextWriterWriteAttribute(writer, GOOD_CAST "version", GOOD_CAST "1.0");
  // xmlTextWriterWriteAttribute(writer, GOOD_CAST "xml:lang", GOOD_CAST "de");
  // xmlTextWriterStartElement(writer, GOOD_CAST "HEADER");
  // xmlTextWriterWriteFormatElement(writer, GOOD_CAST "X_ORDER_ID", "%010d", 53535);
  // xmlTextWriterEndDocument(writer);
#endif

  // xmlDocDumpFormatMemoryEnc(<#xmlDocPtr out_doc#>, <#xmlChar **doc_txt_ptr#>, <#int *doc_txt_len#>, <#const char *txt_encoding#>, <#int format#>)
  // xmlDocDumpFormatMemory(<#xmlDocPtr cur#>, <#xmlChar **mem#>, <#int *size#>, <#int format#>)
  xmlDocDumpFormatMemoryEnc(doc, &xmlbuff, &buffersize, MY_ENCODING, 1);

  // xmlDocDumpFormatMemory(doc, &xmlbuff, &buffersize, 1);
  // printf("%s", GOOD_CAST xmlbuff);

  xmlFree(xmlbuff);

  // xmlSaveFile("rietumu2.xml", doc);
  xmlSaveFileEnc("wildlife1.xml", doc, MY_ENCODING);

  // xmlSaveFormatFile("rietumu3.xml", doc, 1);
  xmlSaveFormatFileEnc("wildlife2.xml", doc, MY_ENCODING, 1);

#if 1
  xmlValidCtxtPtr ctxt;
  int rc = xmlValidateDocument(ctxt, doc);
  if (rc != 0) {
    fprintf(stderr, "Error: xmlValidateDocument() %d\n", rc);
  }
#endif

  xmlFreeDoc(doc);

  return 0;
}
